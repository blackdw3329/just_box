import os

ch_dir = os.chdir("C:\\2301358")

def createFolder(directory):
    try:    
        if not os.path.exists(directory):
            os.makedirs(directory)
    except OSError:
        print('Error: Creating directory.'+ directory)

os.mkdir(".\dir2")