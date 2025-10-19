import random

random.seed(42)

n = 200000
min_val = -10**9
max_val = 10**9
dup_rate = 0.1
dup_cnt = int(n * dup_rate)
rand_cnt = n - dup_cnt

dup_values = [random.randint(min_val, max_val) for _ in range(random.randint(10, 50))]
dup_data = [random.choice(dup_values) for _ in range(dup_cnt)]
rand_data = []
while len(rand_data) < rand_cnt:
    val = random.randint(min_val, max_val)
    if val not in dup_values:
        rand_data.append(val)

data = dup_data + rand_data
random.shuffle(data)

with open('10.in', 'w') as f:
    f.write(f"{n}\n")
    f.write(' '.join(map(str, data)) + '\n')