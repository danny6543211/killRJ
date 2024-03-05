import psutil
import subprocess
import time

import ini


def find_pid(process_name):
    for proc in psutil.process_iter(['pid', 'name']):
        if proc.info['name'] == process_name:
            return proc.info['pid']
    return None


def main():
    subprocess.Popen(ini.RJ_client_path)
    print('Please wait for three seconds...')
    targets_kill = ['8021x.exe', 'suservice.exe', '8021x.exe']
    for t in targets_kill:
        time.sleep(1)
        pid = find_pid(t)
        process = psutil.Process(pid)
        process.kill()


if __name__ == '__main__':
    main()