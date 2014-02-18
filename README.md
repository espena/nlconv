#nlconv

Use this tool to switch back and forth between three different line break conventions:

- Dos/Windows (Carriage Return + Line Feed)
- Linux (Line Feed)
- Apple II and early Mac OS (Carriage Return)

For fixed-length records in a continuous file (without line breaks), this tool can split the files into
multiple lines, one per record. This is crucial for a number of common database import routines, as they
rely on aquiring the data on a line-by-line basis.

##Usage

_nlconv mode [options] [--input &lt;sourcefile&gt;]_

*mode*
<table>
  <tr>
    <td>-d</td><td>--2dos</td>
    <td>Use DOS/Windows style line breaks (Cr+Lf)</td>
  </tr>
  <tr>
    <td>-m</td><td>--2mac</td>
    <td>Use Apple II style line breaks (Cr)</td>
  </tr>
  <tr>
    <td>-n</td><td>--2nux</td>
    <td>Use Linux style line breaks (Lf)</td>
  </tr>
  <tr>
    <td>-h</td><td>--help</td>
    <td>Display usage description.</td>
  </tr>
</table>

*options*
<table>
  <tr>
    <td>-u</td><td>--utf8</td>
    <td>Specify that the input file is UTF-8 encoded.</td>
  </tr>
  <tr>
    <td>-l</td><td>--fixlength &lt;recordlength&gt;</td>
    <td>Specify record length. For fixed-length files without line breaks.</td>
  </tr>
</table>

*sourcefile*

Path to the text file to be converted. If the --fixlength parameter is used, and the input file is
UTF-8 encoded, use the --utf8 option, unless a UTF-8 byte-order marker (BOM) is present at the beginning
of the file. This parameter is optional in that the user may pipe the input data into nlconv instead of
specifying a sourcefile (see below).

To convert a file with mac-formatted newlines to a new file witn dos-style newlines:

`nlconv --2dos --input data-mac-formatted.txt > data-dos-formatted.txt`

###Piping
In addition to reading --input &lt;sourcefile&gt;, _nlconv_ also accepts piped input. The following example
works on Windows, OS X and Linux:

`echo foobarfoobarfoobar | nlconv --2nux --fixlength 3`

