s <- readline(prompt = "Enter a String : ")
suppressWarnings(
if(nchar(s)<=1) {
        cat("Palindrome")
} else {
        s <- strsplit(s,"")[[1]]
        midl <- ceiling(length(s)/2)
        midh <- ceiling(length(s)/2+.05)
        if(all(s[1:midl]==s[length(s):midh])) {
                cat("Palindrome")
        } else {
                cat("Not Palindrome")
        }
}
)