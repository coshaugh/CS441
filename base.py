#!/usr/bin/env python

import os.path
import jinja2
import webapp2

from webapp2_extras import auth
from webapp2_extras import sessions

JINJA_ENVIRONMENT = jinja2.Environment(
	loader = jinja2.FileSystemLoader(os.path.dirname(__file__)+"/templates"))

class BaseHandler(webapp2.RequestHandler):
	@webapp2.cached_property
	def auth(self):
		"""Getter to access the auth instance as a property."""
		return auth.get_auth()

	@webapp2.cached_property
	def user_info(self):
		"""Getter to access a subset of user attributes in the session.

		List of attributes to store in the session is specified in
			config['webapp2_extras.auth']['user_attributes'].
		:returns
			A dictionary with most user information
		"""
		return self.auth.get_user_by_session()

	@webapp2.cached_property
	def user(self):
		"""Getter to access the current logged in user.

		Unlike user_info, it fetches information from the persistence layer and returns an instance of the underlying model.
 
 		:returns
 			The instance of the user model associated to the logged in user.
		"""
		u = self.user_info
		return self.user_model.get_by_id(u['user_id']) if u else None

	@webapp2.cached_property
	def user_model(self):
		"""Returns the implementation of the user model.

		It is consistent with config['webapp2_extras.auth']['user_model'], if set.
		"""
		return self.auth.store.user_model

	@webapp2.cached_property
	def session(self):
		"""Getter to access the current session."""
		return self.session_store.get_session(backend="datastore")
 
 	def render_template(self, view_filename, params=None):
 		if not params:
 			params = {}
 		user = self.user_info
 		params['user'] = user
 		template = JINJA_ENVIRONMENT.get_template(view_filename)
 		self.response.out.write(template.render(params))
 
	def display_message(self, message):
		"""Utility function to display a template with a simple message."""
		params = {
			'message': message
		}
		self.render_template('message.html', params)
 
	# this is needed for webapp2 sessions to work
	def dispatch(self):
		# Get a session store for this request.
		self.session_store = sessions.get_store(request=self.request)

		try:
			# Dispatch the request.
			webapp2.RequestHandler.dispatch(self)
		finally:
			# Save all sessions.
			self.session_store.save_sessions(self.response)

