import subprocess
from multiprocessing import Pool


def run(cmd, norm_num, attack_num):
    p = subprocess.Popen(["bash", "-c", str(cmd)], stdin=subprocess.PIPE)
    p.stdin.write(str(norm_num) + "\n")
    p.stdin.write(str(attack_num) + "\n")
    p.wait()


def do_run(args):
    run("../run dos.ini -c Interval_0_0001 > %d_%d.log"%(args[0], args[1]), args[0], args[1])


params = []
for i in [5, 10]:
    for j in range(0, 21):
        params.append((i, j))

pool = Pool(7)
pool.map(do_run, params)
pool.close()
pool.join()

