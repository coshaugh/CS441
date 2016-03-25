#!/usr/bin/env python

from google.appengine.ext import db

class User(db.Model):
	name = db.StringProperty(required=True)
	password = db.StringProperty()
	email = db.StringProperty()

