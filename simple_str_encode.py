def runLengthEncoding(string):
	if len(string) == 0:
		return ''
	
	count = 0
	encode_char = string[0]
	running_str = ''
	reset_flag = False
	for curr_char in string:
		if curr_char == encode_char:
			count += 1
			reset_flag = False
		else:
			if count == 0:
				count = 1
				encode_char = curr_char
				reset_flag = False
				continue
			running_str += str(count) + encode_char
			count = 1
			encode_char = curr_char
			reset_flag = False
		if count == 9:
			running_str += '9' + encode_char
			count = 0
			reset_flag = True
	if not reset_flag and count > 0:
		running_str += str(count) + encode_char

	return running_str
