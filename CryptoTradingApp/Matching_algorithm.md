
asks = Orderbook.asks
bids = OrderBook.asks

sales = []
sort asks lowest first
sort bids highest first

for ask in asks:
    for bid in bids:
            if bid.Price >= ask.Price # we have a match
            sale = new order()
            sale.Price = ask.Price
            # now workout how much was sold and crete new bids and asks covering anything that was not sold

                if bid.amount == ask.amount: # bid completely clears the ask
                    sale.amount = ask.amount
                    sales.append(sale)
                    bid.amount = 0 # make the bid not processed again
                    # can do no more with ask
                    # go on to next ask
                    break

                if bid.amount > ask.amount: # ask is completely gone. slice the bid
                    sale.amount = ask.amount
                    sales.append(sale)
                    # we adjust the bid in place so it can be used to process the next ask
                    bid.amount = bid.amount - ask.amount
                    # ask is completely gone, so go to next ask
                    break

                if bid.amount < ask.amount: # bid is completely gone, slice the ask
                    sale.amount = bid.amount
                    sales.appent(sale)
                    # update the ask and allow futher bids to process the remaining amount
                    ask.amount = ask.amount - bid.amount
                    bid.amount = 0 # make sure bid is not processed again
                    # some ask remains. so go to the next bid
                    continue




