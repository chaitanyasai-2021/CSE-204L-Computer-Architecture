Program 2: Write a program to implement Trace-route command


import subprocess
import platform

def traceroute(host):
    try:
        if platform.system().lower() == "windows":
            cmd = ['tracert', host]
        else:
            cmd = ['traceroute', host]

        result = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, check=True)

        print(result.stdout)

    except subprocess.CalledProcessError as e:
        print(f"Failed to perform traceroute to {host}: {e}")
    except Exception as e:
        print(f"An error occurred: {e}")

if name == "main":
    host = input("Enter the host or IP address to trace route to: ")
    traceroute(host)