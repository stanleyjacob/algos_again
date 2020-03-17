

def generate_parenthesis(n):
	if n == 0:
		return []
	if n == 1:
		return ['()']
	else:
		my_dict = {'(' : (1, 1)}
		return generate_helper(n, my_dict)

def generate_helper(n, my_str_dict):
	
	new_dict = {}
	key_length = None

	for key, tup in my_str_dict.items():
		stack_count = tup[0]
		num_open_paren = tup[1]
		key_length = len(key) + 1

		if value > 0:
			new_str1 = key + '('
			new_str2 = key + ')'
			if value + 1 <= n:
				if len(new_str1) == 2 * n:
					if value + 1 == 0:
						new_dict[new_str1] = value + 1
				else:
					new_dict[new_str1] = value + 1

			new_dict[new_str2] = value - 1

		else:
			new_str = key + '('
			new_dict[new_str] = value + 1

	if key_length == 2 * n:
		return new_dict.keys()

	else:
		return generate_helper(n, new_dict)


print(generate_parenthesis(3))
