import { createSlice } from '@reduxjs/toolkit'

const initialState = {
    numberOflaptops: 200
}

const laptopSlice = createSlice({
    name: "laptop",
    initialState,
    reducers: {
        orderLaptop: (state) => {
            state.numberOflaptops--
        },
        restockLaptop: (state, action) => {
            state.numberOfcakes = state.numberOfcakes + parseInt(action.payload)
        }

    }
})

export default laptopSlice.reducer

export const { orderLaptop, restockLaptop } = laptopSlice.actions