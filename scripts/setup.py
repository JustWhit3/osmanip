#! /bin/env python

"""This script is executed by CMake in ../ will call make in the root folder before it builds the executable.
"""

import subprocess

# install_cmd = "./scripts/install.sh"
# result = subprocess.Popen(install_cmd, shell=True, stderr=subprocess.PIPE)
# print(result.stderr.read())

pwd = str(subprocess.check_output("pwd"))
if pwd.endswith('\n'):
    pwd = pwd[0:len(pwd) - 1]
cmd = "make all {}".format(str(pwd))
print(cmd)

result = subprocess.Popen(cmd, shell=True, stderr=subprocess.PIPE)
print(result.stderr.read())
