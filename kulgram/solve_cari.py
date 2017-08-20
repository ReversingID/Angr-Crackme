import angr

cari = angr.Project("./cari", load_options={"auto_load_libs":False})

input_len = 12
flag = angr.claripy.BVS("flag", input_len*8)

cari_state = cari.factory.entry_state(args=["./cari", flag])
path_group = cari.factory.path_group(cari_state)

path_group.explore(find=0x4006eb, avoid=0x400691)
                        # '--------------|-------------> ini alamat dimana password benar ditampilkan
                        #                '-------------> ini alamat dimana password salah ditampilkan
found   = path_group.found[0]
flagnya = found.state.se.any_str(flag)

print flagnya
