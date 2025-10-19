import subprocess
import sys

exec_file = "./a.out"  
input_file = "testcase/25.in"

result = subprocess.run(
    ["/usr/bin/time", "-v", exec_file],
    stdin=open(input_file, "r"),
    stdout=subprocess.PIPE,
    stderr=subprocess.PIPE,
    text=True
)


time_used = None
mem_used = None

for line in result.stderr.splitlines():
    if "Elapsed (wall clock) time" in line:
        time_used = line.split(": ", 1)[-1].strip()
    if "Maximum resident set size" in line:
        mem_used = line.split(": ", 1)[-1].strip()

print(f"Time Used: {time_used}")
print(f"Memory Used: {mem_used} KB")