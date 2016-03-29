#!/usr/bin/env python

import webapp2
import logging

from page_handlers import MainHandler, AboutHandler
from accountMgmt import SignupHandler, SetPasswordHandler, LoginHandler
from accountMgmt import LogoutHandler, ForgotPasswordHandler, AuthenticateHandler, VerificationHandler

from config import CONFIG

app = webapp2.WSGIApplication([
	webapp2.Route('/', MainHandler, name='home'),
	webapp2.Route('/signup', SignupHandler),
	webapp2.Route('/<type:v|p>/<user_id:\d+>-<signup_token:.+>', handler=VerificationHandler, name='verification'),
	webapp2.Route('/password', SetPasswordHandler),
	webapp2.Route('/login', LoginHandler, name='login'),
	webapp2.Route('/logout', LogoutHandler, name='logout'),
	webapp2.Route('/forgot', ForgotPasswordHandler, name='forgot'),
	webapp2.Route('/authenticated', AuthenticateHandler, name='authenticated'),
	webapp2.Route('/about', AboutHandler)],
	debug=True, config=CONFIG)

logging.getLogger().setLevel(logging.DEBUG)