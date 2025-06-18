try:
    from ._noo import *
except ImportError as e:
    import warnings
    warnings.warn(
        "C extension _noo not available. Falling back to pure Python implementation (slower):" + str(e),
        ImportWarning,
        stacklevel = 2  # Show the warning in user code, not this module
    )
    from .pynoo import *
