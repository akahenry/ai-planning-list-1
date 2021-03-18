import os

def run_algorithm(algorithm, instance, timelimit = "600", memorylimit = "4000000"):
    process = os.popen(f"ulimit -t {timelimit}; ulimit -v {memorylimit}; ./bin/main {algorithm} {instance}")

    result = process.read()

    if result == "":
        return "-,-,-,-,-\n"
    else:
        return result

bfs_result_file = open("./results/bfs.csv", "w")
astar_result_file = open("./results/astar.csv", "w")
idfs_result_file = open("./results/idfs.csv", "w")
gbfs_result_file = open("./results/gbfs.csv", "w")
idastar_result_file = open("./results/idastar.csv", "w")

with open("./public/8puzzle_instances.txt", "r") as file:
    for line in file.readlines():
        print("bfs")
        bfs_result_file.write(run_algorithm("-bfs", line))
        print("astar")
        astar_result_file.write(run_algorithm("-astar", line))
        print("idfs")
        idfs_result_file.write(run_algorithm("-idfs", line))
        print("gbfs")
        gbfs_result_file.write(run_algorithm("-gbfs", line))
        print("idastar")
        idastar_result_file.write(run_algorithm("-idastar", line))

bfs_result_file.close()
astar_result_file.close()
idfs_result_file.close()
gbfs_result_file.close()
idastar_result_file.close()

astar_result_file = open("./results/astar15puzzle.csv", "w")

with open("./public/15puzzle_instances.txt", "r") as file:
    for line in file.readlines():
        astar_result_file.write(run_algorithm("-astar", line, "30", "10000000"))

astar_result_file.close()