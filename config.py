CONFIG = {
	'webapp2_extras.auth': {
		'user_model' : 'models.User',
		'user_attributes' : ['username','shared_string']
	},
	'webapp2_extras.sessions' : {
		'secret_key' : 'YOUR_SECRET_KEY'
	}
}