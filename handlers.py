#!/usr/bin/env python

import os
import jinja2
import webapp2
from google.appengine.api import users
from userData import *

JINJA_ENVIRONMENT = jinja2.Environment(
	loader = jinja2.FileSystemLoader(os.path.dirname(__file__)+"/templates"))

class mainHandler(webapp2.RequestHandler):
	def get(self):
		user = users.get_current_user()

		if user:
			self.redirect("/profile.html")
		else:
			self.redirect("/login.html")

class profileHandler(webapp2.RequestHandler):
	def get(self):
		user = users.get_current_user()
		title = "PROFILE TITLE"
		greeting = ('Welcome, %s! (<a href="%s">sign out</a>)' % (user.nickname(), users.create_logout_url('/')))
		template_vars = {
		'title' : title,
		'greeting' : greeting
		}

		template = JINJA_ENVIRONMENT.get_template('profile.html')
		self.response.out.write(template.render(template_vars))

class loginHander(webapp2.RequestHandler):
	def get(self):
		title = "LOGIN TITLE"
		greeting = ('<a href="%s">Sign in or register</a>.' % users.create_login_url('/'))
		template_vars = {
		'title' : title,
		'greeting' : greeting
		}

		template = JINJA_ENVIRONMENT.get_template('login.html')
		self.response.out.write(template.render(template_vars))

	# change this post method to cross-reference datastore
	# do not create new user here
	def post(self):
		log_in = self.request.get('log_in')
		new_user = self.request.get('new_user')
		if log_in:
			newUser = User(name=self.request.get("username"), 
				password=self.request.get("password"))
			newUser.put()
		elif new_user:
			self.redirect('newUser.html')

class newUserHandler(webapp2.RequestHandler):
	def get(self):
		title = "NEW USER TITLE"
		template_vars = {
		'title' : title
		}

		template = JINJA_ENVIRONMENT.get_template('newUser.html')
		self.response.out.write(template.render(template_vars))

	def post(self):
		sign_up = self.request.get('sign_up')
		log_in = self.request.get('log_in')
		if sign_up:
			newUser = User(name=self.request.get("username"), 
				password=self.request.get("password"))
			newUser.put()
		elif log_in:
			self.redirect('login.html')

class aboutHandler(webapp2.RequestHandler):
	def get(self):
		title = "ABOUT TITLE"
		template_vars = {
		'title' : title
		}
		template = JINJA_ENVIRONMENT.get_template('about.html')
		self.response.out.write(template.render(template_vars))








