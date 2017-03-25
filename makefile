

M_EXE=cmake-build-debug/test/MemoizedSolver-generate_stats.exe
D_EXE=cmake-build-debug/test/DynamicSolver-generate_stats.exe
OUT=./test/output
TOTAL=1500
REPEAT=3
ARGS=${TOTAL} ${REPEAT}

test_results:
	@echo "testing Dynamic..."
	${D_EXE} ${ARGS} > "${OUT}/dyn ${ARGS}.txt"
	@echo "testing Memoized..."
	${M_EXE} ${ARGS} > "${OUT}/mem ${ARGS}.txt"
