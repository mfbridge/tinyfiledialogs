
#' Save a file
#' @description
#' Prompt the user to save a file with a given extension using a system dialog.
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
#'
#' @returns
#'  A `character(1)` of the selected file, or NULL if the dialog was cancelled.
#'
#' @export

saveFileDialog = function(title = "Save File", filepath = getwd(), filters = "", description = "")
{
    file = .saveFileDialog(title, normalizePath(path.expand(filepath)), length(filters), filters, description)
    if (is.null(file)) return(NULL)
    return(file)
}
