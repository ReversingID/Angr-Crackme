import angr
import logging
# logging.getLogger('angr.engines').setLevel('DEBUG')
strcmp = angr.Project("./strcmp")  # Meload binary
p      = strcmp.factory.path()

# melakukan step sampai branch
p.step()
while len(p.successors) <= 1:   
    p = p.successors[0]
    p.step()

b_left  = p.successors[0]   # Branch left adalah blok if (jika password benar)
b_right = p.successors[1]   # Branch right adalah blok else (jika password salah)

print b_left.state.posix.dumps(0)  # Tampilkan data yg berada di stdin (fd=0)
