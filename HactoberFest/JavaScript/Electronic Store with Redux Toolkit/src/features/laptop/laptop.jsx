import React, { useState } from 'react'

import { useSelector, useDispatch } from 'react-redux'
import { orderLaptop, restockLaptop } from './laptopSlice'

function Laptop() {

    const laptops = useSelector((state) => state.cake)
    const dispatch = useDispatch()

    const [templaptops, settemplaptops] = useState(0)


    const handleOrder = () => {
        dispatch(orderLaptop())

    }
    const handleRestock = () => {
        dispatch(restockLaptop(parseInt(templaptops)))
        settemplaptops(0)
    }
    return (
        <div>
            <h1>Laptops</h1>
            <h2>Number of Laptops - {laptops.numberOflaptops}</h2>
            <button onClick={handleOrder}>Order Laptop</button>
            <input
                type='number'
                value={templaptops}
                onChange={(e) => settemplaptops(e.target.value)}
            />
            <button onClick={handleRestock}>ReStock</button>
        </div>
    )
}

export default Laptop