import { createSlice } from '@reduxjs/toolkit'
import { orderLaptop } from '../laptop/laptopSlice'


const initialState = {
    numberOfMobiles: 200
}

const mobileSlice = createSlice({
    name: "mobile",
    initialState,
    reducers: {
        orderMobile: (state) => {
            state.numberOfMobiles--
        },
        reStockMobile: (state, action) => {
            state.numberOfMobiles = state.numberOfMobiles + parseInt(action.payload)
        }
    },
    extraReducers: builder => {
        builder.addCase(orderMobile, (state, action) => {
            state.numberOfMobiles--
        })
    }
})



export default mobileSlice.reducer

export const { orderMobile, reStockMobile } = mobileSlice.actions