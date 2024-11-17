#AP21110010253
import os
import platform

command = "-n 1" if platform.system().lower() == "windows" else "-c 1"

def ping(host):
  response = os.popen(f"ping {command} {host}")
  output = response.readlines()
  return output

print(ping("google.com"))
