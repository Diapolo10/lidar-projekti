# type: ignore

import os
import subprocess

read_the_docs_build = os.environ.get('READTHEDOCS') == 'True'

if read_the_docs_build:
    subprocess.call('doxygen', shell=True)

extensions = ['breathe']
breathe_projects = { 'lidar-projekti': 'xml' }
breathe_default_project = "lidar-projekti"
templates_path = ['_templates']
source_suffix = '.rst'
master_doc = 'index'
project = 'lidar-projekti'
copyright = '2021, lidar-projekti'
author = 'lidar-projekti'
version = '1.0'
release = '1.0'
language = None
exclude_patterns = ['_build']
pygments_style = 'sphinx'
todo_include_todos = False
html_static_path = ['_static']
htmlhelp_basename = 'lidar-projektidoc'
latex_elements = {}
latex_documents = [
  (master_doc, 'lidar-projekti.tex', 'lidar-projekti Documentation',
   'lidar-projekti', 'manual'),
]
