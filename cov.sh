# Capture coverage and open HTML report
lcov --capture --directory build/ --output-file coverage.info
genhtml coverage.info --output-directory coverage_report
xdg-open coverage_report/index.html
