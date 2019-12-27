# eMail
Environment requirements:
+ OS: Ubuntu 18.04 x64
+ Python: 3.7.5
+ Evaluation ([install](https://rc.partners.org/kb/article/2702) | [eMail setup](https://askubuntu.com/questions/51467/how-do-i-setup-an-email-account-in-evolution))

### How to run
```sh
    python3 main.py
```

## 1. Maildir guide
Currently, maildir is a directory that stores email messages as files. Maildir works with Courier, a mail server that provides folders and quotas for the email accounts on your hosting account.

The folders inside the mail directory are subdirectories such as *.Drafts*, *.Trash* and *.Sent*. Each of these folders contain three additional subdirectories called *tmp*, *new* and *cur*.

+ **tmp** - This subdirectory stores email messages that are in the process of being delivered. It may also store other kinds of temporary files.
+ **new** - This subdirectory stores messages that have been delivered but have not yet been seen by any mail application, such as webmail or Outlook.
+ **cur** - This subdirectory stores messages that have already been viewed by mail applications, like webmail or Outlook.