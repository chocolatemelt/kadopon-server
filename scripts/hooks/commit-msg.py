#!/usr/bin/python

import sys
import re
import subprocess


# #<issue number> | <commit msg>
# <git keyword> #<issue number> | <commit msg>

# SAVE THIS FILE TO: .git/hooks/commit-msg

MESSAGE_REGEX = '^#\d+\s\|\s'


def current_branch_name():
  """Gets the current GIT branch name.

  Returns:
    string: The current branch name.
  """
  return subprocess.check_output(['git', 'rev-parse', '--abbrev-ref', 'HEAD'])


def valid_commit_message(message):
  """Function to validate the commit message.

  Args:
    message (str): The message to validate.

  Returns:
    bool: True for valid messages, False otherwise.
  """
  if not re.match(MESSAGE_REGEX, message):
    name = current_branch_name()
    print "ERROR: Commit message does not comply with supreme overlord Kev's standards"
    print 'Example1: #420 | generic commit message'
    print 'Example2: closes #420 | blaze it'
    return False

  print 'Commit message is valid.'
  return True


def main():
  """Main function."""
  message_file = sys.argv[1]
  try:
    txt_file = open(message_file, 'r')
    commit_message = txt_file.read()
  finally:
    txt_file.close()

  if not valid_commit_message(commit_message):
    sys.exit(1)

  sys.exit(0)


if __name__ == "__main__":
  main()
