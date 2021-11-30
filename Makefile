# Inspired by: https://blog.mathieu-leplatre.info/tips-for-your-makefile-with-python.html

INSTALL_STAMP := .install.stamp
ARDUINO_DOCS := arduinodocs.py
POETRY := $(shell command -v poetry 2> /dev/null)
MYPY := $(shell command -v mypy 2> /dev/null)

.DEFAULT_GOAL := help

.PHONY: all
all: build-docs

.PHONY: help
help:
	@echo "Please use 'make <target>', where <target> is one of"
	@echo ""
	@echo "  build-docs  build Doxygen documentation"
	@echo "  all         build Doxygen documentation"
	@echo "  clean       remove all temporary files listed in .gitignore"
	@echo ""
	@echo "Check the Makefile to know exactly what each target is doing."

install: $(INSTALL_STAMP)
$(INSTALL_STAMP): pyproject.toml
	@if [ -z $(POETRY) ]; then echo "Poetry could not be found. See https://python-poetry.org/docs/"; exit 2; fi
	$(POETRY) run pip install --upgrade pip setuptools
	$(POETRY) install
	touch $(INSTALL_STAMP)

.PHONY: build-docs
build-docs: $(INSTALL_STAMP)
    # Configured in pyproject.toml
	$(POETRY) run python $(ARDUINO_DOCS)

.PHONY: clean
clean:
    # Delete all files in .gitignore
	git clean -Xdf

