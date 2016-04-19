#!/usr/bin/env python

from base import BaseHandler

class MainHandler(BaseHandler):
	def get(self):
		self.render_template('home.html')

class AboutHandler(BaseHandler):
	def get(self):
		title = "ABOUT TITLE"
		template_vars = {
		'title' : title
		}
		self.render_template('about.html', template_vars)








