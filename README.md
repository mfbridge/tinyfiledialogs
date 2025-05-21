
<!-- README.md is generated from README.Rmd. Please edit that file -->

# tinyfiledialogs

<!-- badges: start -->
<!-- badges: end -->

This is a wrapper of Guillaume Vareille’s portable & cross-platform
C/C++ library
<a href='https://sourceforge.net/projects/tinyfiledialogs/'>`tinyfiledialogs`</a>
for displaying various prompts, compiled using using `Rcpp` in order to
bundle it as a standalone R package. Modal dialogs exist for message
boxes & file, folder, color, and text inputs using familiar standard
system dialogs.

The motivation for this wrapper follows a quest to have local Shiny apps
able to select one *or more* files using a standard system dialog
*without* relying on the web browser via `shiny::fileInput()` (as files
are unnecessarily “uploaded” to a temporary directory which can take a
while), and a few other solutions did not present the more modern
Windows open/save dialog with a quick links sidebar. Unfortunately, I
also had issues with calling the `tfd_*()` functions of the C library
that are included for compatibility with R’s `base::.C()` without
creating stubs anyway, so here we are.

## Installation

You can install the latest development version of the R package like so:

``` r
install.packages("remotes")
remotes::install_github("https://github.com/mfbridge/tinyfiledialogs")
```

## Example

### Selecting multiple files (!)

This is one thing that `rstudioapi::selectFile()` cannot do:

``` r
csv.files = tinyfiledialogs::openFileDialog(
    title = "Open File(s)",
    description = "CSV Files (*.csv)",
    filters = c("*.csv"), 
    multiple = T
)

if (is.null(csv.files)) {
    tinyfiledialogs::messageBox(
        title = "Error", 
        message = "No files were selected.", 
        icontype = "error"
    )
} else {
    print(csv.files)
}
```
