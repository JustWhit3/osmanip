# List of future implementations

## New features

- Add **progress spinner**.
- Add an extra feature for **3D images visualization** on the terminal (not GUI), like [this example](https://www.a1k0n.net/2021/01/13/optimizing-donut.html), but extended to other kind of forms.

## Improvements

- Extend the ProgressBar class usage to non-standard types also (vectors, maps etc...). Basically update the [`update`](https://github.com/JustWhit3/osmanip/blob/main/src/progress_bar.cpp#:~:text=void%20ProgressBar%20%3Cbar_type%3E%3A%3Aupdate,Update%20of%20the%20progress) method in order to support also non-standard types as argument.
- Add remaining time feature to each progress bar.
- Make the library a cross-platform software, in order to support also other operating systems than Unix ones.
- Improve the compilation using CMake tools.

## Bugs

- Correct a small bug for which, for the `ProgressBar<float>` and `ProgresBar<double>` istances, the `update` method, when using a high difference between the value of `setMin` and `setMax` (for example `setMin( 1.1f )` and `setMax( 13.4f )` in an iterating loop variable of `i += 0.1f`), show the progress indicator sometimes not precise (see the `width` variable definition inside the `update` method, maybe is this one the problem).
