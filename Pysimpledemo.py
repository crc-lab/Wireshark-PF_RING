import subprocess
import sys
import PySimpleGUI as sg

"""
	Demo Program - Realtime output of a shell command in the window
		Shows how you can run a long-running subprocess and have the output
		be displayed in realtime in the window.
"""

sg.theme('Black')

def main():
	layout = [
                [sg.Button('Launch', bind_return_key=True , button_color=('white', 'springgreen4')), sg.Button('Exit', button_color=('white', 'black'))],
				[sg.Output(size=(110,30))],
				#[sg.T('Promt> '), sg.Input(key='-IN-', do_not_clear=False)],
				#[sg.Button('Run', bind_return_key=True), sg.Button('Exit')] ]
             ]

	window = sg.Window('Standalone PF RING', layout)

	while True:             # Event Loop
		event, values = window.read()
		# print(event, values)
		if event in (None, 'Exit'):
			break
		elif event == 'Launch':
			runCommand()
	window.close()


def runCommand():
	#nop = None
	""" run shell command
	@param cmd: command to execute
	@param timeout: timeout for command execution
	@param window: the PySimpleGUI window that the output is going to (needed to do refresh on)
	@return: (return code from command, command output)
	"""
    
	p = subprocess.Popen(['pfring1','-i','enp3s0'] ,cwd='home/mubbashir/PF_RING/userland/examples', shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
	#p = subprocess.Popen(['ls'] , shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
	output = ''
	for line in p.stdout:
		line = line.decode(errors='replace' if (sys.version_info) < (3, 5) else 'backslashreplace').rstrip()
		output += line
		print(line)
		#window.refresh() if window else nop        # yes, a 1-line if, so shoot me

	#retval = p.wait(timeout)
	return (output)


main()

