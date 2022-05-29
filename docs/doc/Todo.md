# List of future implementations

## New features

- Extend the 2D terminal-graphics to 3D.

## Improvements

- Make the library a cross-platform software, in order to support also other operating systems than Unix ones.
- Improve the compilation using CMake tools.
- Add time-elapsed info to the progress bar.

## Bugs

- Correct a small bug for which, for the `ProgressBar<float>` and `ProgresBar<double>` istances, the `update` method, when using a high difference between the value of `setMin` and `setMax` (for example `setMin( 1.1f )` and `setMax( 13.4f )` in an iterating loop variable of `i += 0.1f`), show the progress indicator sometimes not precise (see the `width` variable definition inside the `update` method, maybe is this one the problem).
- Improve the ProgressBar, with floating-point template type, time-remaining computation and precision for iterating variables with more than one 0 after comma.
