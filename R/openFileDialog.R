
#' Select one or more files
#' @description
#' Prompt the user to select one or more files (if allowed) of the given extensions using the standard system dialog.
#'
#'
#' @typed title: base::character
#'  Window title
#' @typed filepath: base::character
#'  A default filename and/or path
#' @typed filters: base::character
#'  File extension filter patterns
#' @typed description: base::character
#'  Generic file type descriptor string
#' @typed multiple: base::logical
#'  Allow multiple files to be selected?
#'
#' @returns
#'  A `character()` vector of the selected file(s), or NULL if the dialog was cancelled.
#'
#' @export

openFileDialog = function(title = "Open File", filepath = getwd(), filters = "", description = "", multiple = F)
{
    files = .openFileDialog(title, normalizePath(path.expand(filepath)), length(filters), filters, description, multiple)

    if (is.null(files)) return(NULL)
    return(strsplit(files, split = "|", fixed = T)[[1]])
}
