import angr
from   socket import ntohl # Untuk konversi big endian ke little endian 32bit
from   ctypes import c_int

"""Mengubah unsigned int menjadi signed int"""
def signed(x):
    return c_int(x).value

prog       = angr.Project("./basic", load_options={"auto_load_libs":False})
basic_addr = prog.loader.main_bin.get_symbol('basic').addr # Mendapatkan alamat dari fungsi basic
basic      = prog.factory.callable(basic_addr) # Alamat dari fungsi basic()
s          = prog.factory.entry_state()

""" Membuat symbolic variable x, y dan z dengan besar 32bit"""
x = s.se.BVS('x', 32)
y = s.se.BVS('y', 32)
z = s.se.BVS('z', 32)
""" solver """
s.add_constraints(basic(x, y, z) == 31337)

""" Mengambil hasil dan menkonversinya menjadi signed little endian 32bit """
nilai_x = signed(ntohl(s.se.any_int(x)))
nilai_y = signed(ntohl(s.se.any_int(y)))
nilai_z = signed(ntohl(s.se.any_int(z)))

print "x = {0}".format(nilai_x)
print "y = {0}".format(nilai_y)
print "y = {0}".format(nilai_z)
