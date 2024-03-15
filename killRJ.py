import psutil
import subprocess
import time

import ini


def find_pid(process_name: str):
    for proc in psutil.process_iter(['pid', 'name']):
        if proc.info['name'] == process_name:
            return proc.info['pid']
    return None

def kill(target_kill: list):
    for t in target_kill:
        time.sleep(0.5)
        pid = find_pid(t)
        process = psutil.Process(pid)
        process.kill()

def main():
    print('Please wait for seconds...')
    
    target_kill = ['8021x.exe', 'suservice.exe', '8021x.exe']
    subprocess.Popen(ini.RJ_client_path)
    time.sleep(3)
    kill(target_kill)


if __name__ == '__main__':
    main()