
#' Choose a folder
#' @description
#' Prompt the user to select a folder.
#'
#'
#' @typed title: base::character
#'  \cr Window title
#' @typed path: base::character
#'  \cr A default path
#'
#' @returns
#'  A `character(1)` of the selected folder, or NULL if the dialog was cancelled.
#'
#' @export

selectFolderDialog = function(title = "Choose Folder", path = getwd())
{
    file = .selectFolderDialog(title, normalizePath(path.expand(path)))
    if (is.null(file)) return(NULL)
    return(file)
}
