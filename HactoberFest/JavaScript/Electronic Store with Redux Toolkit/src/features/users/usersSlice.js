import {createSlice, createAsyncThunk} from '@reduxjs/toolkit'

import axios from 'axios'


const initialState = {
    loading:false,
    users :[],
    error:""
}

// rejected,sucess,error
export const fetchusers = createAsyncThunk('/user/fetchusers', async ()=>{
    const response = await axios.get("https://jsonplaceholder.typicode.com/users")
    return await response.data
})



const usersSlice = createSlice({
    name:"user",
    initialState,
    extraReducers: builder => {
        builder.addCase(fetchusers.fulfilled, (state,action)=>{
            state.loading=false
            state.users = action.payload
            state.error=""
        })
        builder.addCase(fetchusers.pending, (state)=>{
            state.loading=true
            state.users = []
            state.error=""
        })
        builder.addCase(fetchusers.rejected, (state,action)=>{
            state.loading=false
            state.users = []
            state.error=action.error.message
        })
    }
})

export default usersSlice.reducer

