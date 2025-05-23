% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{inputBox}
\alias{inputBox}
\title{Input a string}
\arguments{
\item{title}{\code{base::character} \cr Window title}

\item{message}{\code{base::character} \cr A message displayed alongside the input}

\item{value}{\code{base::character} \cr The default input string}
}
\value{
A \code{character(1)} of the entered string, or NULL if the dialog was cancelled.
}
\description{
Get a string from the user and display a message using a system dialog.
}
