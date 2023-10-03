from fileinput import filename
import pagan

inpt = 'Python Developer'
img = pagan.Avatar(inpt, pagan.SHA512)
img.show()
outpath = 'output/'
filename = inpt
img.save(outpath, filename)
img.change('new input', pagan.SHA256)
#criando avatar utilizando pagan