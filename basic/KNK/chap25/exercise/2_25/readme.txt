The Shift-JIS encoding for kanji requires either one or two bytes per character.
If the first byte of a character is between 0x81 and 0x9f or between 0xe0 and 0xef,
a second byte is required. (Any other byte is treated as a whole character.) The 
second byte must be between 0x40 and 0x7e or between 0x80 and 0xfc. (All ranges are
inclusive.) For each of the following strings, give the value that the mbcheck fun-
-ction of Section 25.2 will return when passed that string as its argument, assuming
that multibyte characters are encoded using Shift-JIS int the current locale.

"\x05\x87\x80\x36\xed\xaa"
(\x05) (\x87\x80) (\x36) (\xed(\xaa)   error! -> -1

"x20\xe4\x50\x88\x3f"
(\x20) (\xe4\x50) (x88(x3f)   error! -> -1

"\xde\xad\xbe\xef"
(\xde) (\xad)  (\xbe) (\xef   error! -> -1

"\x8a\x60\x92\x74\x41"
(\x8a\x60) (\x92\x74) (\x41) -> 0

