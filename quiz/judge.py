#!/usr/bin/env python3
import os
import subprocess
import sys

def read(filename):
    with open(filename, 'rb') as fp:
        return fp.read()

def run(ifn):
    # 編譯 testcode.c
    compile_cmd = ['gcc', '-std=c99', '-O2', 'testcode.c', '-o', 'a.exe']
    subprocess.run(compile_cmd, check=True)

    # 執行程式，輸入 ifn，輸出到 slave.out
    with open('slave.out', 'wb') as fout, open(ifn, 'rb') as fin:
        result = subprocess.run(['./a.exe'], stdin=fin, stdout=fout, stderr=subprocess.PIPE)
    return result.returncode

def main():
    score = 0
    subtasks = eval(read('subtasks.py'))

    for subtask in subtasks:
        for trial in subtask[1:]:
            ifn, ofn, tl, ml, ol = trial
            print(f'{ifn} ', end='')

            # 執行程式
            try:
                res = run(ifn)
            except subprocess.CalledProcessError:
                print('RE 0')
                continue

            if res != 0:
                print('RE 0')
            else:
                # 判題 special.py
                try:
                    wa = subprocess.run(
                        ['python', 'special.py', ifn, ofn, 'slave.out'],
                        stdout=subprocess.PIPE, stderr=subprocess.PIPE
                    )
                    if wa.returncode != 0:
                        print('WA 0')
                    else:
                        print(f'AC {subtask[0]}')
                        score += subtask[0]
                except Exception:
                    print('WA 0')

    print(score)

if __name__ == '__main__':
    main()
    input('press enter to continue...')
