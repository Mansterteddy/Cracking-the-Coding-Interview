class logit(object):

    def __init__(self, logfile="out.log"):
        self.logfile = logfile

    def __call__(self, func):
        log_string = func.__name__ + " was called"
        print(log_string)
        with open(self.logfile, 'a') as opened_file:
            opened_file.write(log_string + '\n')

        self.notify()

    def notify(self):
        pass

@logit()
def myfunc1():
    pass

class email_logit(logit):
    def __init__(self, email="zhangyuan@ict.ac.cn", *args, **kwargs):
        self.email = email
        super(email_logit, self).__init__()

    def notify(self):
        print("Send email.")
        pass
