.PHONY: test clean
test:
	python3 ../tools/reference/build_reference.py
	python3 ../tools/reference/compare_logic.py
	python3 ../tools/reference/compare_positions.py
	python3 ../tools/reference/test_full_level.py
clean:
	rm -f ../tools/reference/work/*.so
