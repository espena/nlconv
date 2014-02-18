#nlconv

Use this tool to switch forth and back between the three different line break conventions:

- Dos/Windows (Carriage Return + Line Feed)
- Linux (Line Feed)
- Apple II and early Mac OS (Carriage Return)

For fixed-length records in a continuous file (without line breaks), this tool can split the files into
multiple lines, one per record. This is crucial for a number of common database import routines, as they
rely on aquiring the data on a line-by-line basis.

##Usage

_nlconv mode [options] --input <file>_

  _mode:_
  <table>
    <tr><td>-d</td><td>--2dos</td><td>Use DOS/Windows style line breaks (Cr+Lf)</td></tr>
    <tr><td>-m</td><td>--2mac</td><td>Use Apple II style line breaks (Cr)</td></tr>
    <tr><td>-n</td><td>--2nux</td><td>Use Linux style line breaks (Lf)</td></tr>
    <tr><td>-h</td><td>--help</td><td>Display usage description.</td></tr>
  </table>

  _options:_
  <table>
    <tr><td>-u</td><td>--utf8</td><td>Specify that the input file is UTF-8 encoded.</td></tr>
    <tr><td>-l</td><td>--fixlength &lt;recordlength&gt;</td><td>Specify record length. For fixed-length files without line breaks.</td></tr>
  </table>
  
  `nlconv { [--2dos] | [--2mac] | [--2nix] ] } [--fixlength <length>] [--utf8] [--input <datafile>]`




`nlconv { [--2dos] | [--2mac] | [--2nix] | [--2fix --length <length> [ [--cr] | [--lf] | [--crlf] ] ] } [--utf8] [--input <datafile>]`



`nlconv -2dos -i data-mac.txt > data-dos.txt`

