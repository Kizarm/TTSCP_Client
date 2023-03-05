#!/usr/bin/python3
# -*- coding: utf-8 -*-
'''
Tohle je asi nejjednodušší způsob jak převést kódování češtiny
z utf-8 (nebo jiného) na iso-8859-2, přičemž výstup zůstane v ASCII.
Je potřeba přerušit string uvozovkami, pokud za esc x následují více
jak 2 hexadecimální znaky (fce replace), jinak to C++ špatně interpretuje.
'''
import re;            # regex je asi nejjednodušší cesta
def replace (p, s):   # rekurzívní fce, přidává ty "" dokud není hotovo
  m = p.search(s)
  if m == None: return s
  n = m.start() + 4   # pozice, kam se "" vsunou
  r = s[0:n] + '\"\"' + s[n:]
  return replace (p, r)
  
if __name__ == '__main__':
  s = 'Příliš žluťoučký kůň úpěl ďábelské ódy.'
  print (s)
  c = s.encode('iso-8859-2') # iso bytes
  #print (c)
  c = str(c)[1:].replace('\'','\"') # C/C++ syntax
  p = re.compile('(\\\\x[0-9a-f]{3,})')
  r = replace(p, c)
  print (r)
  '''
  f = open ('x.txt', 'w')
  f.write (r)
  f.close ()
  '''
