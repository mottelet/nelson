# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/).

## 0.6.12 (2022-12-27)

### Added

Graphics module:

First big step to do plot 2D and 3D with Nelson. Some features are missing and will come in next releases.
Current version is usable and show plots possibilities of Nelson.

Do not hesitate to create features requests or bug reports. Contributions are welcome.

Implemented features:

- `figure` creates an figure window.
- `cla` clears figure.
- `axes` creates cartesian axes.
- `axis` set axis limits and aspect ratios.
- `cla` clears axes.
- `zlim` set or get z-axis limits.
- `ylim` set or get y-axis limits.
- `xlim` set or get x-axis limits.
- `clim` set colormap limits.
- `line` creates primitive line.
- `plot` 2-D line plot.
- `plot3` 3-D line plot.
- `rgbplot` Plot colormap.
- `subplot` Create axes in tiled positions.
- `newplot` Prepare to produce a new plot.
- `semilogx` Semilog plot (x-axis has log scale).
- `semilogy` Semilog plot (y-axis has log scale).s
- `quiver` Quiver or vector plot.
- `surf` creates surface plot.
- `text` creates text descriptions to data points.
- `title` adds title.
- `legend` adds legend to axes.
- `xlabel` Label x-axis.
- `ylabel` Label y-axis.
- `zlabel` Label z-axis.
- `grid` Display or hide axes grid lines.
- `spy` Visualize sparsity pattern of matrix.
- `image` displays image from array.
- `imagesc` displays image from array with scaled colors.
- `cylinder` creates cylinder.
- `sphere` creates sphere.
- `close` close one or more figures.
- `gcf` get current figure graphics object.
- `gca` get current axes graphics object.
- `groot` return graphic root object.
- `refresh` redraws current figure.
- `ishold` get current hold state.
- `hold` retain current plot when adding new plots.
- `view` Camera line of sigh.
- `saveas` Save figure to specific file format.
- `copygraphics` Copy plot to clipboard.
- `isValidGraphicsProperty` check property name is valid for a graphics object type name.
- `isprop`, `properties`, `isequal`, `eq`, `display`, `set`, `get` for Graphics Object type.
- `isgraphics` Check if it is an graphics object handles.
- `colstyle` Parse color and style from string.
- `is2D` Checks if ax is a 2-D Polar or Cartesian axes.
- `colorbar` Colorbar showing color scale.
- `colormap` View and set current colormap.
- colormaps:
  - `autumn`: Autumn colormap array.
  - `gray`: Gray colormap array.
  - `parula`: Parula colormap array.
  - `spring`: Spring colormap array.
  - `summer`: Summer colormap array.
  - `winter`: Winter colormap array.

```markdown
░░ٌٌٌӇ░ٌٌٌƛ░ٌٌٌƤ░ٌٌٌƤ░ٌٌٌƳ ░ٌٌٌ░ٌٌٌƝ░ٌٌٌЄ░ٌٌٌƜ░ٌٌٌ░ٌٌٌ Ƴ░ٌٌٌЄ░ٌٌٌƛ░ٌٌٌƦ░ٌٌٌ!░
╚═════════ ೋღ❤ღೋ ═════════╝
```

## 0.6.11 (2022-11-25)

### Added

- `normest` 2-norm estimate.

- logical operators `&`, `|` , `&&`, `||` for sparses matrix managed.

- doxygen documentation generated by Github CI for each release.

- `--noaudio` CLI argument disable audio (module) in Nelson.

- [#783](http://github.com/Nelson-numerical-software/nelson/issues/783): Fedora 37 support.

- an example to build mexFunction using Rust.

- geometry module:

  - `rotx`: 3x3 transformation matrix for rotations around x-axis
  - `roty`: 3x3 transformation matrix for rotations around y-axis
  - `rotz`: 3x3 transformation matrix for rotations around z-axis

- `spones` replaces non zero sparse matrix elements with ones.

- `rot90` faster for 2D matrix.

### Changed

- timeout `--timeout` CLI argument and `system` with timeout return error code `258` on Windows and `134` others platforms.

- `test_run` catchs error code about test aborted (timeout).

- `exit` does not allow value > 255 on Linux and MacOS.

- [#776](http://github.com/Nelson-numerical-software/nelson/issues/776): internal dependencies between modules reworked.

- Uses MKL or OpenBlas if detected on linux and MacOs (Nelson is faster on Linux and MacOs).

### Fixed

- basic terminal was closed immediately if stdin was null.

- Github Actions CI warnings.

- [#778](http://github.com/Nelson-numerical-software/nelson/issues/778): ArchLinux Github CI was broken.

## 0.6.10 (2022-10-31)

### Added

- [#750](http://github.com/Nelson-numerical-software/nelson/issues/750): Qt 6.4.0 support (win64 release embed Qt6.4.0).

- [#733](http://github.com/Nelson-numerical-software/nelson/issues/733): minimal build and optional installation on MacOs, Linux and Windows.

### Fixed

- [#762](http://github.com/Nelson-numerical-software/nelson/issues/762): MacOs CI was broken (libomp no more detected).

- [#776](http://github.com/Nelson-numerical-software/nelson/issues/776): CodeQL Analyze was broken.

- [#739](http://github.com/Nelson-numerical-software/nelson/issues/739): special case with empty cell.

- buildhelp did not return some errors.

### Changed

- [#755](http://github.com/Nelson-numerical-software/nelson/issues/755): Boost 1.80 support (default on Windows)

- [#753](http://github.com/Nelson-numerical-software/nelson/issues/753): move from boost::filesystem to std::filesystem. (It should have no impact for users ...)

- Path functions returns sensitive path on Windows. `cd ('c:/program files')` returns true path `C:/Program Files`.

- fileparts builtin updated to be more compatible.

- normalizePath internal function reworked.

- internal files functions reworked and factorized.

## 0.6.9 (2022-09-28)

### Added

- linear algebra module:

  - `rref`: Gauss-Jordan elimination.
  - `orth`: Range space of a matrix.
  - `subspace`: Angle between two subspaces.
  - `planerot`: Givens plane rotation.
  - `condeig`: Condition number with respect to eigenvalues.
  - `bandwidth`: Lower and upper matrix bandwidth.
  - `isbanded`: Determine if matrix is within specific bandwidth.

- audio module:

  - `sound`: Convert matrix of signal data to sound and play it.
  - `soundsc`: Scale data and play as sound.
  - `mu2lin`: Convert audio data from mu-law to linear signal.
  - `lin2mu`: Convert audio data from linear singal to mu-law.

- elementary functions module:

  - `toeplitz`: Toeplitz matrix.
  - `hadamard`: Hadamard matrix.
  - `wilkinson`: Wilkinson's eigenvalue test matrix.
  - `vander`: Vandermonde matrix.
  - `rosser`: Classic symmetric eigenvalue test problem.
  - `nextpow2`: Next higher power of 2.
  - `permute`: Permute array dimensions.
  - `ipermute`: Inverse permute array dimensions.
  - `rot90`: Rotate array 90 degrees.

- special functions module:

  - `dot`: Dot product.
  - `cross`: Cross product.

- string module:

  - `isletter`: Determine which characters are letters.

- data analysis module:

  - `cumsum`: Cumulative sum.
  - `cumprod`: Cumulative product.

### Changed

- [#715](http://github.com/Nelson-numerical-software/nelson/issues/715): update `{fmt}` to 9.1.0.

- Nelson uses [`simdutf`](https://github.com/simdutf/simdutf) library to convert characters encoding faster.

- shorcuts `&&` and `||` reworked.

- assign behavior with empty matrix.

- [#702](http://github.com/Nelson-numerical-software/nelson/issues/702): Ubuntu 18.04 CI removed on Github.

- Remove definitively Appveyor CI.

- C++ API: `getContentAsDoubleScalar`, `getContentAsSingleScalar`, `getContentAsInteger8Scalar`, ... , `getContentAsInteger64Scalar` can check if it is an integer value.

- `addgateway`, `removegateway`, `gatewayinfo` builtin moved in `modules_manager` module (reduces dependency)

### Fixed

- [#722](http://github.com/Nelson-numerical-software/nelson/issues/722): MS MPI runtime v10.1.2.

- [#723](http://github.com/Nelson-numerical-software/nelson/issues/723): MacOS CI was broken.

- [#737](http://github.com/Nelson-numerical-software/nelson/issues/737): profiler failed with `sind` example.

- [#739](http://github.com/Nelson-numerical-software/nelson/issues/739): special case with empty cell.

- [#741](http://github.com/Nelson-numerical-software/nelson/issues/741): `ones` and `zeros` do not manager logical as typename.

## 0.6.8 (2022-08-27)

### Added

- [#573](http://github.com/Nelson-numerical-software/nelson/issues/574): `diff` differences and discret derivatives.

- `peaks`: peaks function.

- parallel module:

  - `fetchNext`: Retrieve next unread outputs from FevalFuture array.
  - `afterAll`: Run function after all functions finish running in the background.
  - `afterEach`: Run function after each functions finish running in the background.

- signal processing module:

  - `hann`: Hann window.
  - `hamming`: Hamming window.
  - `bartlett`: Bartlett window.
  - `blackman`: Blackman window.
  - `sinc`: sinc function.
  - `filter2`: 2-D digital filter.
  - `fft2`: Two-dimensional discrete Fourier Transform.

- time functions:

  - `weekday`: Day of week.
  - `eomday`: Last day of month.
  - `etime`: Time elapsed between date vectors.
  - `date`: Current date as character vector.
  - `timeit`: Measure time required to run function.
  - `addtodate`: Modify date number by field.

- trigonometric functions:

  - `rad2deg`: Convert angle from radians to degrees.
  - `deg2rad`: Convert angle from degrees to radians.
  - `cart2pol`: Transforms Cartesian coordinates to polar or cylindrical.
  - `pol2cart`: Transforms polar or cylindrical coordinates to Cartesian.
  - `cart2sph`: Transforms Cartesian to spherical coordinates.
  - `sph2cart`: Transform spherical coordinates to Cartesian.
  - `sech`: Hyperbolic secant.
  - `secd`: Secant of argument in degrees.
  - `sec`: Secant of angle in radians.
  - `csch`: Hyperbolic cosecant.
  - `cscd`: Cosecant of argument in degrees.
  - `csc`: Cosecant of argument in radians.
  - `coth`: Hyperbolic cotangent.
  - `cot`: Cotangent of argument in radians.
  - `cotd`: Cotangent of argument in degrees.
  - `atand`: Inverse tangent in degrees.
  - `atan2d`: Four-quadrant inverse tangent in degrees.
  - `sinpi`: Computes sin(X \* pi) accurately.
  - `cospi`: Computes cos(X \* pi) accurately.
  - `asind`: Inverse sine in degrees.
  - `asinh`: Inverse hyperbolic sine.
  - `acosh`: Inverse hyperbolic cosine.
  - `acosd`: Inverse cosine in degrees.
  - `acoth`: Inverse hyperbolic cotangent.
  - `acsc`: Inverse cosecant in radians.
  - `acscd`: Inverse cosecant in degrees.
  - `acsch`: Inverse hyperbolic cosecant.
  - `asec`: Inverse secant in radians.
  - `asecd`: Inverse secant in degrees.
  - `asech`: Inverse hyperbolic secant.
  - `acot`: Inverse cotangent in radians.
  - `acotd`: Inverse cotangent in degrees.

- prettier is used to format .xml, .md files.

- Code format (.xml, .md, c++) checker added to Github CI.

### Changed

- `system` builtin:

  - returns time execution
  - timeout input argument can be set to kill process after n seconds.

- [#687](http://github.com/Nelson-numerical-software/nelson/issues/687): Uses BS thread pool 3.3.0.

- Windows 32 bits threads support: due to threading limitations with MKL, openMP and others threads
  computation threads are limited to 4 threads on Windows 32 bits.

- [#683](http://github.com/Nelson-numerical-software/nelson/issues/683): MacOS Catalina removed on Github CI (no more officially supported).

- Help chapter titles all start with a capital letter.

- [#771](http://github.com/Nelson-numerical-software/nelson/issues/771): Fedora 36 Github CI replaces Fedora 35 Github CI.

### Fixed

- [#689](http://github.com/Nelson-numerical-software/nelson/issues/689): `c = computer` returns an error.
- [#691](http://github.com/Nelson-numerical-software/nelson/issues/691): help generation crashs if copyright tag is empty.
- [#35](http://github.com/Nelson-numerical-software/nelson/issues/35): datenum does not support vectorization.
- `or`, `and` do not manage matrix operator scalar case.

## 0.6.7 (2022-07-27)

### Added

- `str2func` manages anonymous function.

- Parallel functions (part 2):

  - `cancelAll`: Stop all functions running in the background.
  - `cancel`: Stop function running in the background.
  - `wait`: Wait for futures to be completed.
  - `Diary` property for `FevalFuture` object.

- CITATION.cff with human- and machine-readable citation information for software.

### Changed

- localization files `.pot`, `.po` updated.

### Fixed

- [#679](http://github.com/Nelson-numerical-software/nelson/issues/679): uniformize path for includes and libraries.

## 0.6.6 (2022-06-27)

### Added

- Parallel functions (part 1):

  - `parfeval`: Run function on parallel background thread pool worker.
  - `backgroundPool`: Environment for running code in the background.
  - `fetchOutputs`: Retrieve results from function running in the background.

- [#666](http://github.com/Nelson-numerical-software/nelson/issues/666): `ls` function: List folder contents.

- [#655](http://github.com/Nelson-numerical-software/nelson/issues/655): help viewer embedded (available on all platforms).

### Changed

- LGTM replaced by CodeQL (Thanks to Github for their support)

- [#662](http://github.com/Nelson-numerical-software/nelson/issues/662): Snap uses Core22 and Qt6 (all dependencies are up-to-date).

- [#668](http://github.com/Nelson-numerical-software/nelson/issues/668): `maxNumCompThreads` detects numbers of physical cores on Windows.

- matrix of handles supported.

- [#676](http://github.com/Nelson-numerical-software/nelson/issues/676): use fmtlib 9.0

### Fixed

- [#659](http://github.com/Nelson-numerical-software/nelson/issues/659): qhelpgenerator on macOs after brew Qt6.3.0 update.

- [#661](http://github.com/Nelson-numerical-software/nelson/issues/661): CodeQL warnings.

## 0.6.5 (2022-05-26)

### Added

- [#572](http://github.com/Nelson-numerical-software/nelson/issues/572): `pow2`: Base 2 exponentiation.

- `audioread`, `audiowrite` supports new file formats `.mp3`, `.flac`, `.caf` (Thanks to libsndfile).

- MacOs 12 Monterey Github CI.

- [#634](http://github.com/Nelson-numerical-software/nelson/issues/634): Ubuntu 22.04 CI.

### Changed

- [#631](http://github.com/Nelson-numerical-software/nelson/issues/631): Qt6 used as default distribution on some OS platforms.

  For backport compatibility only Qt5.15.x and Qt6.3 (or more) are supported.

  - Windows 64 bits: Qt6.3
  - Windows 32 bits: Qt5.15.x
  - Ubuntu 22.04: Qt6.3
  - Ubuntu 20.04, 18.04: Qt5.15.x
  - MacOs Monterey: Qt6.3
  - MacOs BigSur, Catalina: Qt5.15.x
  - Others OS platforms: Qt version based on distributed Qt version.

- [#636](http://github.com/Nelson-numerical-software/nelson/issues/636): docker image uses bullseye image.

- `system` builtin: multithread rework.

- [#633](http://github.com/Nelson-numerical-software/nelson/issues/633): libsndfile 1.1.0 used.

- Windows build uses `/permissive-` option.

- [#646](http://github.com/Nelson-numerical-software/nelson/issues/646): `warndlg`, `questdlg`, `errordlg`, `helpdlg` reworked to better Qt6 support.

### Fixed

- Dark theme detection with Gnome.

- [#642](http://github.com/Nelson-numerical-software/nelson/issues/642): `rand` was not thread safe.

- [#648](http://github.com/Nelson-numerical-software/nelson/issues/648): Ubuntu 18.04 CI failed.

- [#651](http://github.com/Nelson-numerical-software/nelson/issues/651): MacOs monterey crashs at exit with mpi module.

## 0.6.4 (2022-04-24)

### Changed

- [#590](http://github.com/Nelson-numerical-software/nelson/issues/590): Nelson's license moved to LGPL v3.0 and GPL v3.0 and uses SPDX format.

- Nelson uses [Hack](https://sourcefoundry.org/hack/) font.

- Linux 64 bits and 32 bits uses same main script.

- [#594](http://github.com/Nelson-numerical-software/nelson/issues/594): `.pot` used to generate en_US.

### Added

- 'sscanf' reworked to manage unicode characters and speed optimization.

- French translations imported from Weblate (Thanks to contributors)

- Dark theme detected and applied on Linux, MacOS and Windows.

- [#559](http://github.com/Nelson-numerical-software/nelson/issues/559): `formattedDisplayText` function: Capture display output as string.

- Better detection Qt6 or Qt5 with CMake.

### Fixed

- Main Nelson's font was not applied on some OS platforms (ex: MacOS Catalina)

- [#622](http://github.com/Nelson-numerical-software/nelson/issues/622): `isreal(sqrt(i^4))` did not return true.

- Nelson's help indexing is faster (x100).

## 0.6.3 (2022-03-26)

### Changed

- [#596](http://github.com/Nelson-numerical-software/nelson/issues/596): Tests results display use emoji if terminal supports Unicode.

### Added

- Packaging:

  - [#603](http://github.com/Nelson-numerical-software/nelson/issues/603): Nelson as snap package for Linux.
  - [#605](http://github.com/Nelson-numerical-software/nelson/issues/605): [Package request] Chocolatey package manager for Windows.
  - [#582](http://github.com/Nelson-numerical-software/nelson/issues/582): Nelson available as Portable apps.

- add information for Software Center (Linux desktop, icons).

- `nelson` Main script to start Nelson (superceed others scripts).

- `isunicodesupported` function: Detect whether the current terminal supports Unicode.

- `dlsym` function: search nearest symbol name if value entry is not found.

- `terminal_size` function:Query the size of the terminal window.

- [#598](http://github.com/Nelson-numerical-software/nelson/issues/598): `sscanf` function read formatted data from strings.

### Fixed

- [#599](http://github.com/Nelson-numerical-software/nelson/issues/599): `make install` step in CI for linux and MacOs.

- [#601](http://github.com/Nelson-numerical-software/nelson/issues/601): embed all tests on linux and macos install.

## 0.6.2 (2022-02-26)

### Changed

- [#576](http://github.com/Nelson-numerical-software/nelson/issues/576): C++17 Compiler required to build Nelson.

- [#581](http://github.com/Nelson-numerical-software/nelson/issues/581): Github CI platforms list extended (ArchLinux, Fedora, Ubuntu 18.04, MacOs BigSur).

- [#539](http://github.com/Nelson-numerical-software/nelson/issues/539): Visual studio 2022 build on Windows

  - Visual studio 2022 solution upgraded,
  - Github CI and Appveyor use VS 2022 image,
  - boost 1.78 (VS 2022 x86, x64 build),
  - Eigen 3.4 stable branch (Feb 06/22),
  - MSVC 2022 support added to build C/C++ code easily "on fly" on Windows,
  - slicot 5.0 (VS 2022 x86, x64 build),
  - libffi (VS 2022 x86, x64 build),
  - taglib 1.12 (VS 2022 x86, x64 build),
  - hdf5 1.12.1 (VS 2022 x86, x64 build),
  - matio 1.5.21 (VS 2022 x86, x64 build),
  - all others windows dependencies rebuilt with VS 2022.
  - [#505](http://github.com/Nelson-numerical-software/nelson/issues/505): libCurl 7.81 on Windows.
  - [#524](http://github.com/Nelson-numerical-software/nelson/issues/524): oneApi 2022.1 on Windows.

### Added

- Nelson uses `JuliaMono-Regular` font as default.
- [#567](http://github.com/Nelson-numerical-software/nelson/issues/567): `...` in cells if character vector is too long.

### Fixed

- [#587](http://github.com/Nelson-numerical-software/nelson/issues/587): implicit cast to string array for horzcat and vertcat operators.
- [#562](http://github.com/Nelson-numerical-software/nelson/issues/562): `format long` complex do not display expected precision.
- scale factor for integer values did not display as expected.
- [#561](http://github.com/Nelson-numerical-software/nelson/issues/561): `0^0` did not return expected value.
- [#560](http://github.com/Nelson-numerical-software/nelson/issues/560): many warnings fixed (Thanks to new PVS-Studio and cppcheck).
- cmake `WITH_SLICOT`, `WITH_FFTW`, `ENABLE_CLANG_TIDY_FIX` were not documented.
- [#584](http://github.com/Nelson-numerical-software/nelson/issues/584): docker files updated to support C++17 and new libraries.
- [#591](http://github.com/Nelson-numerical-software/nelson/issues/591): Innosetup display glitch with `Nelson's website` button.

## 0.6.1 (2022-01-31)

### Changed

- display of all types reworked to be `pixel perfect`. (a small sentence but a big rework)

### Added

- `format` extended to manage: `compact`, `loose`, `longE`, `longG`, `hex`, `bank`, `rational`.
- [#507](http://github.com/Nelson-numerical-software/nelson/issues/507): `celldisp`: Display cell array contents.
- [#548](http://github.com/Nelson-numerical-software/nelson/issues/548): `hypot` builtin: Square root of sum of squares.
- [#555](http://github.com/Nelson-numerical-software/nelson/issues/555): `rsf2csf` function: Convert real Schur form to complex Schur form.
- `CHANGELOG` 0.6.x family.

## Previous changelog

[Changelog v0.5.x](CHANGELOG-0.5.x.md)

[Changelog v0.4.x](CHANGELOG-0.4.x.md)

[Changelog v0.3.x](CHANGELOG-0.3.x.md)

[Changelog v0.2.x](CHANGELOG-0.2.x.md)

[Changelog v0.1.x](CHANGELOG-0.1.x.md)
