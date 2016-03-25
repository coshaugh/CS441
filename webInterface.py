#!/usr/bin/env python

import webapp2

from handlers import mainHandler
from handlers import loginHander
from handlers import newUserHandler
from handlers import profileHandler
from handlers import aboutHandler

app = webapp2.WSGIApplication(
	[('/', mainHandler),
	('/login.html', loginHander),
	('/newUser.html', newUserHandler),
	('/profile.html', profileHandler),
	('/about.html', aboutHandler)],
	debug=True)