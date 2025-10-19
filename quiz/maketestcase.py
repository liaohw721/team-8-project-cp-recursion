import random
import time

random.seed(time.time())


N = 200000
D = 200000
min_val = -10**9
max_val = 10**9

idx_dup_rate = random.uniform(0.4, 0.8)
query_hit_rate = random.uniform(0.7, 0.9)


uniq_count = int(N * (1 - idx_dup_rate))
dup_count = N - uniq_count

idx_uniqs = random.sample(range(min_val, max_val+1), uniq_count)

dup_pool = random.sample(range(min_val, max_val+1), max(10, int(0.05 * N)))
idx_dups = [random.choice(dup_pool) for _ in range(dup_count)]
idxs = idx_uniqs + idx_dups
random.shuffle(idxs)

vals = [random.randint(min_val, max_val) for _ in range(N)]


events = [random.randint(1, 2) for _ in range(D)]
queries = []
hit_num = int(D * query_hit_rate)


idx_hit_queries = random.choices(idxs, k=hit_num)

remain_num = D - hit_num
remain_queries = []
idx_set = set(idxs)
while len(remain_queries) < remain_num:
    q = random.randint(min_val, max_val)
    if q not in idx_set:
        remain_queries.append(q)
queries = idx_hit_queries + remain_queries
random.shuffle(queries)


with open('25.in', 'w') as f:
    f.write(f"{N} {D}\n")
    for idx, val in zip(idxs, vals):
        f.write(f"{idx} {val}\n")
    for event, query in zip(events, queries):
        f.write(f"{event} {query}\n")