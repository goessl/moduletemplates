from setuptools import Extension, setup

setup(
    name = 'noo',
    version = '0.0.1',
    packages = ['noo'],
    ext_modules = [
        Extension(
            name = 'noo._noo',
            sources = ['noo/_noomodule.c'],
        ),
    ]
)
