#nlconv

Use this tool to switch forth and back between the three different line break conventions:

- Dos/Windows (Carriage Return + Line Feed)
- Linux (Line Feed)
- Apple II and early Mac OS (Carriage Return)

For fixed-length records in a continuous file (without line breaks), this tool can split the files into
multiple lines, one per record. This is crucial for a number of common database import routines, as they
rely on reading one line at a time.

##Usage

`nlconv { [-2dos] | [-2mac] | [-2nix] | [-2fix -l <length> [ [-cr] | [-lf] | [-crlf] ] ] } [-utf8] [-i <datafile>]`

`nlconv -2dos -i data-mac.txt > data-dos.txt`

