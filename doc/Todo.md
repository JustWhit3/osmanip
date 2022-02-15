# List of future implementations

## New features

- Add an extra feature for **3D images visualization** on the terminal (not GUI), like [this example](https://www.a1k0n.net/2021/01/13/optimizing-donut.html), but extended to other kind of forms.

## Improvements

- Make the library a cross-platform software, in order to support also other operating systems than Unix ones.
- Improve the compilation using CMake tools.
- Add time-elapsed info to the progress bar.
- Update the `tcs` map and modify the clear-screen ANSI sequences in order to return different values for a given `n` for `\u001b[{n}J`:
  - n=0 clears from cursor until end of screen.
  - n=1 clears from cursor to beginning of screen.
  - n=2 clears entire screen.
- Update the `tcs` map and modify the clear-screen ANSI sequences in order to return different values for a given `n` for `\u001b[{n}K`:
  - n=0 clears from cursor to end of line.
  - n=1 clears from cursor to start of line.
  - n=2 clears entire line.

## Bugs

- Correct a small bug for which, for the `ProgressBar<float>` and `ProgresBar<double>` istances, the `update` method, when using a high difference between the value of `setMin` and `setMax` (for example `setMin( 1.1f )` and `setMax( 13.4f )` in an iterating loop variable of `i += 0.1f`), show the progress indicator sometimes not precise (see the `width` variable definition inside the `update` method, maybe is this one the problem).
- Improve the ProgressBar, with floating-point template type, time-remaining computation and precision for iterating variables with more than one 0 after comma.
