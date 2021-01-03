
class Valuation_Model:

	def __init__(ticker, industry, similar_tickers):
		pass

	# save vol + price, buy or sell
	def load_stock_buffer(start_date, time_step):
		pass

	# save vol + price, buy or sell
	def load_option_buffer(start_date, time_step, strike_price, date, is_call):
		pass

	def twitter_scraper():
		pass

	def news_scraper(site_name):
		pass

	def process_income_sheet(is_pdf):
		pass

	def process_cash_flow(cf_pdf):
		pass

	def process_balance_sheet(b_pdf):
		pass

	def calculate_dcf(discount_rate):
		pass
	
