#include "tfd.h"

//' @name messageBox
//' @title Display a message
//' @description Show a modal dialog with configurable buttons and icon.
//'
//' @typed title: base::character
//'     \cr Window title
//' @typed message: base::character
//'     \cr A message to display
//' @typed diagtype: base::character
//'     \cr Dialog type (buttons), one of: "ok", "okcancel", "yesno", "yesnocancel"
//' @typed icontype: base::character
//'     \cr Icon displayed on the dialog, one of: "info", "warning", "error", "question"
//' @typed value: base::integer
//'     \cr Default button focus depending on dialog type. 0 for cancel/no, 1 for ok/yes, and 2 for no when diagtype is "yesnocancel"
//'
//'
//' @returns
//' A `character(1)` of the entered string, or NULL if the dialog was cancelled.
//
//' @export
// [[Rcpp::export]]
SEXP messageBox(CharacterVector title, CharacterVector message, CharacterVector diagtype = "ok", CharacterVector icontype = "info", IntegerVector value = 1) {
    return IntegerVector({tinyfd_messageBox(title(0), message(0), diagtype(0), icontype(0), value(0))});
}

//' @name inputBox
//' @title Input a string
//' @description Get a string from the user and display a message using a system dialog.
//'
//' @typed title: base::character
//'     \cr Window title
//' @typed message: base::character
//'     \cr A message displayed alongside the input
//' @typed value: base::character
//'     \cr The default input string
//'
//'
//' @returns
//' A `character(1)` of the entered string, or NULL if the dialog was cancelled.
//
//' @export
// [[Rcpp::export]]
SEXP inputBox(CharacterVector title, CharacterVector message, SEXP value) {
    char * input;

    if (value == R_NilValue) {
        input = tinyfd_inputBox(title(0), message(0), 0);
    } else {
        input = tinyfd_inputBox(title(0), message(0), (CharacterVector(value))(0));
    }

    if (input) {
        return CharacterVector(input);
    } else {
        return R_NilValue;
    }
}

// [[Rcpp::export(.saveFileDialog)]]
SEXP saveFileDialog(CharacterVector title, CharacterVector filepath, IntegerVector nfilters, CharacterVector filters, CharacterVector description) {
    std::vector<char*> _filters;
    for (auto filter : filters) _filters.push_back((char*)filter);

    char * file = tinyfd_saveFileDialog(title(0), filepath(0), nfilters(0), _filters.data(), description(0));

    if (file) {
        return CharacterVector(file);
    } else {
        return R_NilValue;
    }
}

// [[Rcpp::export(.openFileDialog)]]
SEXP openFileDialog_(CharacterVector title, CharacterVector filepath, IntegerVector nfilters, CharacterVector filters, CharacterVector description, IntegerVector multiple) {
    std::vector<char*> _filters;
    for (auto filter : filters) _filters.push_back((char*)filter);

    char * file = tinyfd_openFileDialog(title(0), filepath(0), nfilters(0), _filters.data(), description(0), multiple(0));

    if (file) {
        return CharacterVector(file);
    } else {
        return R_NilValue;
    }
}


// [[Rcpp::export(.selectFolderDialog)]]
SEXP selectFolderDialog(CharacterVector title, CharacterVector path) {
    char * folder = tinyfd_selectFolderDialog(title(0), path(0));

    if (folder) {
        return CharacterVector(folder);
    } else {
        return R_NilValue;
    }
}

//' @name colorChooser
//' @title Pick a color
//' @description Pick a color using a system dialog.
//'
//' @typed title: base::character
//'     \cr Window title
//' @typed hexrgb: base::character
//'     \cr Pre-selected color
//'
//' @returns
//' A `character(1)` of the selected hex value, or NULL if the dialog was cancelled.
//
//' @export
// [[Rcpp::export]]
SEXP colorChooser(CharacterVector title, CharacterVector hexrgb) {
    uint8_t rgb[3], value[3];

    char * color = tinyfd_colorChooser(title(0), hexrgb(0), rgb, value);

    if (color) {
        return CharacterVector(color);
    } else {
        return R_NilValue;
    }
}
